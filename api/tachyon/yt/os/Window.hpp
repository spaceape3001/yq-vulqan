////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/typedef/window.hpp>

namespace yq::tachyon {

    class Window;
    struct ViewerCreateInfo;
    
    /*! \brief Window Information
    
        Information for windows.
    */
    class WindowInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all window informations
        static const std::vector<const WindowInfo*>&    all();
        
        //! Standard constructor for the camera information
        WindowInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    
    /*
        Right *now*, the window is assumed to be simple....
    */


    /*! \brief The window
    
        This will represent the OS/GUI/Abstraction window
        
        Commands on this will go direct into the OS mechanism 
        (even *if* it's thread-unsafe).
    */
    class Window : public Tachyon {
        YQ_TACHYON_INFO(WindowInfo);
        YQ_TACHYON_DATA(WindowData)
        YQ_TACHYON_SNAP(WindowSnap)
        YQ_TACHYON_DECLARE(Window, Tachyon)
    public:    
    
        static void init_info();

        WindowID    id() const { return WindowID(UniqueID::id()); }

        void        cmd_show();
        void        cmd_hide();

    protected:
    
        void        snap(WindowSnap&) const;

        //! Default constructor
        Window(const ViewerCreateInfo&, const Param&p = {});
        
        //! Default destructor
        ~Window();
        
    };

}
