////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/typedef/mass.hpp>

namespace yq::tachyon {
    class MassMeta : public ModelMeta {
    public:
        template <typename C> struct Writer;
        MassMeta(std::string_view, ModelMeta&, const std::source_location& sl = std::source_location::current());
    protected:
        ~MassMeta();
    };
    
    /*! \brief Mass model to something
    */
    class Mass : public Model {
        YQ_TACHYON_META(MassMeta)
        YQ_TACHYON_DATA(MassData)
        YQ_TACHYON_SNAP(MassSnap)
        YQ_TACHYON_DECLARE(Mass, Model)
    public:
    
        static constexpr const Type kType   = Type::Mass;

        Mass(const Param&p={});
        virtual ~Mass();
        
        static void init_meta();
        
        MassID id() const { return MassID{ UniqueID::id()}; }
        
    protected:
        
        void    snap(MassSnap&) const;
        void    finalize(MassData&) const;
    };
}
YQ_TYPE_DECLARE(yq::tachyon::MassID)
