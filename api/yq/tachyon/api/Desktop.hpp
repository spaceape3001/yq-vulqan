////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/typedef/cursor.hpp>
#include <yq/tachyon/typedef/desktop.hpp>
#include <yq/tachyon/typedef/joystick.hpp>
#include <yq/tachyon/typedef/keyboard.hpp>
#include <yq/tachyon/typedef/monitor.hpp>
#include <yq/tachyon/typedef/mouse.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {

    struct AppCreateInfo;
    struct ViewerCreateInfo;

    class Desktop;
    
    /*! \brief Desktop Information
    
        Information for desktops
    */
    class DesktopInfo : public ManagerInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all desktop informations
        static const std::vector<const DesktopInfo*>&    all();
        
        //! Standard constructor for the desktop information
        DesktopInfo(std::string_view, ManagerInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    

    /*! \brief A user desktop (ie, X11, Windows, Mac, GLFW, SDL, etc)
    
        This is any user desktop, whether direct or via an abstraction library.  (ie, this is *OUR* abstraction)
    */
    class Desktop : public Manager {
        YQ_TACHYON_INFO(DesktopInfo);
        YQ_TACHYON_DATA(DesktopData)
        YQ_TACHYON_SNAP(DesktopSnap)
        YQ_TACHYON_DECLARE(Desktop, Manager)
    public:    
    
        enum class C {
            Cursor,
            Joystick,
            Keyboard,
            Monitor,
            Mouse,
            Window
        };
        
        using ControlFlags  = Flags<C>;
    
        struct Param : public Manager::Param {
            ControlFlags    control = ALL;
            
            Param();
        };

        static void init_info();

        DesktopID           id() const { return DesktopID(UniqueID::id()); }

        using Manager::create;
        virtual Window*     create_window(const ViewerCreateInfo&) { return nullptr; }
        
        virtual CursorID    cursor(StdCursor) const { return {}; }
        
        virtual bool        is_running() const { return false; }

        bool    does(cursor_t) const;
        bool    does(joystick_t) const;
        bool    does(keyboard_t) const;
        bool    does(monitor_t) const;
        bool    does(mouse_t) const;
        bool    does(window_t) const;

    protected:
    
        void        snap(DesktopSnap&) const;
 
        //virtual void    receive(const post::PostCPtr&) override;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Desktop(const AppCreateInfo&, const Param&p);
        
        //! Default destructor
        ~Desktop();
        
        ControlFlags const  m_control;
        
    };

}
