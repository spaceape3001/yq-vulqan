////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/Window.hpp>
#include <tachyon/os/WindowData.hpp>
#include <tachyon/os/WindowInfoWriter.hpp>
#include <tachyon/msg/Post.hpp>
#include <ya/commands/ui/HideCommand.hpp>
#include <ya/commands/ui/ShowCommand.hpp>
#include <yq/meta/Init.hpp>
#include <tachyon/vulkan/ViSurface.hpp>
#include <yt/app/ViewerCreateInfo.hpp>

namespace yq::tachyon {

    struct WindowInfo::Repo {
        std::vector<const WindowInfo*> all;
    };
    
    WindowInfo::Repo& WindowInfo::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const WindowInfo*>&    WindowInfo::all()
    {
        return repo().all;
    }

    WindowInfo::WindowInfo(std::string_view name, TachyonInfo& base, const std::source_location& sl) : 
        TachyonInfo(name, base, sl)
    {
        set(Type::Window);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Window::Window(const ViewerCreateInfo& vci) : Tachyon(Param{.name=vci.title}), m_windowMode(vci.wmode)
    {
    }

    Window::~Window()
    {
    }
    
    void Window::cmd_hide()
    {
        mail(new HideCommand({.source=this, .target=this}));
    }
    
    void Window::cmd_show()
    {
        mail(new ShowCommand({.source=this, .target=this}));
    }

    ViSurfacePtr    Window::create_surface() const
    {
        return {};
    }

    void Window::snap(WindowSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Window::init_info()
    {
        auto w   = writer<Window>();
        w.abstract();
        w.description("OS/GUI Window, on the desktop");

        auto wt = writer<WindowID>();
        wt.description("Window Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Window)
YQ_TYPE_IMPLEMENT(yq::tachyon::WindowID)
