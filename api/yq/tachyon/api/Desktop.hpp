////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/typedef/desktop.hpp>

namespace yq::tachyon {

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
    
        static void init_info();

        DesktopID            id() const { return DesktopID(UniqueID::id()); }

    protected:
    
        void        snap(DesktopSnap&) const;
 
        //virtual void    receive(const post::PostCPtr&) override;
        virtual PostAdvice  advise(const Post&) const override;

        //! Default constructor
        Desktop(const Param&p = {});
        
        //! Default destructor
        ~Desktop();
        
    };

}
