////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/Window.hpp>
#include <yq/tachyon/os/WindowData.hpp>
#include <yq/tachyon/os/WindowMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/command/ui/HideCommand.hpp>
#include <yq/tachyon/command/ui/ShowCommand.hpp>
#include <yq/meta/Init.hpp>
#include <yq/tachyon/vulkan/ViSurface.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>

namespace yq::tachyon {

    struct WindowMeta::Repo {
        std::vector<const WindowMeta*> all;
    };
    
    WindowMeta::Repo& WindowMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const WindowMeta*>&    WindowMeta::all()
    {
        return repo().all;
    }

    WindowMeta::WindowMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
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
    
    void Window::init_meta()
    {
        auto w   = writer<Window>();
        w.abstract();
        w.description("OS/GUI Window, on the desktop");

        auto wt = writer<WindowID>();
        wt.description("Window Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Window>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Window)
YQ_TYPE_IMPLEMENT(yq::tachyon::WindowID)
