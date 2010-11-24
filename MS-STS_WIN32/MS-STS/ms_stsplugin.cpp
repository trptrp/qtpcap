#include "ms_sts.h"
#include "ms_stsplugin.h"

#include <QtCore/QtPlugin>

MS_STSPlugin::MS_STSPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MS_STSPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MS_STSPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MS_STSPlugin::createWidget(QWidget *parent)
{
    return new MS_STS(parent);
}

QString MS_STSPlugin::name() const
{
    return QLatin1String("MS_STS");
}

QString MS_STSPlugin::group() const
{
    return QLatin1String("");
}

QIcon MS_STSPlugin::icon() const
{
    return QIcon(QLatin1String(":/wireshark.ico"));
}

QString MS_STSPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MS_STSPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MS_STSPlugin::isContainer() const
{
    return false;
}

QString MS_STSPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MS_STS\" name=\"mS_STS\">\n</widget>\n");
}

QString MS_STSPlugin::includeFile() const
{
    return QLatin1String("ms_sts.h");
}

Q_EXPORT_PLUGIN2(ms_stsplugin, MS_STSPlugin)
