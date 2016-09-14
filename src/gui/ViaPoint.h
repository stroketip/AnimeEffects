#ifndef GUI_VIAPOINT_H
#define GUI_VIAPOINT_H

#include <QWidget>
#include <QPlainTextEdit>
#include "util/NonCopyable.h"
#include "gl/DeviceInfo.h"
#include "core/Project.h"
namespace gui { class ResourceDialog; }
namespace gui { class MainMenuBar; }

namespace gui
{

class ViaPoint : private util::NonCopyable
{
public:
    ViaPoint(QWidget* aParent);

    void setProject(core::Project* aProject);

    void setMainMenuBar(MainMenuBar* aMainMenuBar);
    MainMenuBar* mainMenuBar() const { return mMainMenuBar; }

    ResourceDialog* resourceDialog() const { return mResDialog; }
    void createResourceDialog();

    void setLogView(QPlainTextEdit* aLogView);
    void pushLog(const QString& aText);

    void setGLDeviceInfo(const gl::DeviceInfo&);
    const gl::DeviceInfo& glDeviceInfo() const;

    util::Signaler<void()> onVisualUpdated;

private:
    QWidget* mParent;
    core::Project* mProject;
    MainMenuBar* mMainMenuBar;
    ResourceDialog* mResDialog;
    QPlainTextEdit* mLogView;
    gl::DeviceInfo mGLDeviceInfo;
};

} // namespace gui

#endif // GUI_VIAPOINT_H