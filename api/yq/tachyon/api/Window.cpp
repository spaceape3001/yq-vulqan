////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Window.hpp>
#include <yq/tachyon/api/WindowBind.hpp>
#include <yq/tachyon/api/WindowData.hpp>
#include <yq/tachyon/api/WindowInfoWriter.hpp>
#include <yq/tachyon/api/Post.hpp>

namespace yq::tachyon {

    WindowBind::WindowBind(const Window* v) : m_window(v ? v->id() : WindowID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    Window::Window(const ViewerCreateInfo&, const Param& p) : Tachyon(p)
    {
    }

    Window::~Window()
    {
    }

    PostAdvice    Window::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const WindowBind* p = dynamic_cast<const WindowBind*>(&pp)){
            if(p->window() != id())
                return REJECT;
        }
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
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Window)
