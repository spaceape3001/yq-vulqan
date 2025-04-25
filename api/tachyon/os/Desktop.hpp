////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <tachyon/api/Manager.hpp>
#include <tachyon/typedef/cursor.hpp>
#include <tachyon/typedef/desktop.hpp>
#include <tachyon/typedef/joystick.hpp>
#include <tachyon/typedef/keyboard.hpp>
#include <tachyon/typedef/monitor.hpp>
#include <tachyon/typedef/mouse.hpp>
#include <tachyon/typedef/window.hpp>

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
        virtual Window*     create(window_k, const ViewerCreateInfo&) { return nullptr; }
        
        virtual CursorID    cursor(StdCursor) const { return {}; }
        
        virtual std::vector<const Monitor*>   monitors() const { return {}; }
        
        //virtual bool        is_running() const { return false; }

        bool    does(cursor_k) const;
        bool    does(joystick_k) const;
        bool    does(keyboard_k) const;
        bool    does(monitor_k) const;
        bool    does(mouse_k) const;
        bool    does(window_k) const;

    protected:
    
        void        snap(DesktopSnap&) const;

        //! Default constructor
        Desktop(const AppCreateInfo&, const Param&p);
        
        //! Default destructor
        ~Desktop();
        
        ControlFlags const  m_control;
        
    };
}

YQ_TYPE_DECLARE(yq::tachyon::DesktopID)
