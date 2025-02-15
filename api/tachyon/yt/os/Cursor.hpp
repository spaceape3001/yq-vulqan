////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/typedef/cursor.hpp>

namespace yq::tachyon {

    class Cursor;
    
    /*! \brief Cursor Information
    
        Information for cursors.
    */
    class CursorInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all cursor informations
        static const std::vector<const CursorInfo*>&    all();
        
        //! Standard constructor for the camera information
        CursorInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };
    

    /*! \brief A cursor
    
        Cursor... that thing that generally moves with the mouse movement, ie the cross, the hand, etc
    */
    class Cursor : public Tachyon {
        YQ_TACHYON_INFO(CursorInfo);
        YQ_TACHYON_DATA(CursorData)
        YQ_TACHYON_SNAP(CursorSnap)
        YQ_TACHYON_DECLARE(Cursor, Tachyon)
    public:    
    
        static void init_info();

        CursorID            id() const { return CursorID(UniqueID::id()); }

    protected:
    
        void        snap(CursorSnap&) const;


        //! Default constructor
        Cursor(const Param&p = {});
        
        //! Default destructor
        ~Cursor();
    };

}

YQ_TYPE_DECLARE(yq::tachyon::CursorID)

