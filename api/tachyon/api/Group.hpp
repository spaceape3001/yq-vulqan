////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/typedef/layer.hpp>

namespace yq::tachyon {
    class GroupMeta : public TachyonMeta {
    public:
        template <typename C> struct Writer;
        GroupMeta(std::string_view, TachyonMeta&, const std::source_location& sl = std::source_location::current());
    protected:
        ~GroupMeta();
    };
    
    /*! \brief Group/Group of things (context provided by its parent)
    */
    class Group : public Tachyon {
        YQ_TACHYON_INFO(GroupMeta)
        YQ_TACHYON_DATA(GroupData)
        YQ_TACHYON_SNAP(GroupSnap)
        YQ_TACHYON_DECLARE(Group, Tachyon)
    public:
    
        Group(const Param&p={});
        virtual ~Group();
        
        static void init_info();
        
        GroupID id() const { return GroupID{ UniqueID::id()}; }

    protected:
        
        void    snap(GroupSnap&) const;
        void    finalize(GroupData&) const;
    };
}
YQ_TYPE_DECLARE(yq::tachyon::GroupID)
