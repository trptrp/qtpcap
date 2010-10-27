#include "qtpcap.h"
/*********************************************************
* 进程:
* 这个是程序的核心部分，完成数据包的截获
* 参数:
* pParam: 用户选择的用来捕获数据的网卡的名字
*********************************************************/
int CaptureThread(LPVOID pParam)
{
    const char* pCardName=(char*)pParam; // 转换参数，获得网卡名字
    pcap_t* adhandle;
    char errbuf[PCAP_ERRBUF_SIZE];
    // 打开网卡，并且设置为混杂模式
    adhandle=pcap_open_live(pCardName,65535,1,1000,errbuf);
    pcap_dumper_t* dumpfile;
    // 建立存储捕获网络数据包的文件
    dumpfile=pcap_dump_open(adhandle, "packet.dat");
    int re;
    pcap_pkthdr* header; // Header
    u_char* pkt_data; // 数据包内容指针
    // 从网卡或者文件中不停读取数据包信息
    while((re=pcap_next_ex(adhandle,&header,(const u_char**)&pkt_data))>=0)
    {
        // 将捕获的数据包存入文件
        pcap_dump((unsigned char*)dumpfile,header,pkt_data);
    }
    return 0;
}

int main(int argc, char **argv)
{
    pcap_if_t* alldevs;
    pcap_if_t* d;
    char errbuf[PCAP_ERRBUF_SIZE];
    char ** devName;
    pcap_findalldevs(&alldevs,errbuf); // 获得网络设备指针
    int devIndex=0;
    for(d=alldevs;d;d=d->next) // 枚举网卡然后添加到ComboBox中
    {
        devIndex++;
        printf("%d,%s,%s\n",devIndex,d->description,d->name);  // d->name就是我们需要的网卡名字字符串
        devName[devIndex]=d->name;  // 自己的需要保存到你的相应变量中去
    }
    int i;
    printf("请输入一个数字，并以回车结束！\n");
    scanf("%d",&i);
    printf("%s\n",devName[i]);
    CaptureThread(devName[i]);
}



