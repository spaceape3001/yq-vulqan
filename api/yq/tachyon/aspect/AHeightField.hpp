////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/interface/IHeightField.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetHeightFieldSpecCommand;
    class SetHeightFieldCommand;
    class SetHeightFieldUrlCommand;

    class AHeightField : public IHeightField, public virtual Tachyon::Helper {
    public:
    
        HeightFieldCPtr         height_field() const override;
        Url                     height_field(url_k) const override;
        virtual void            height_field(set_k, const HeightFieldCPtr&) override;
        virtual void            height_field(set_k, const Url&) override;

        bool                    height_field(disabled_k) const { return false; }
        bool                    height_field(settable_k) const { return true; }

        const HeightFieldCPtr&  height_field(ref_k) const { return m_heightField; }

    // unfortunately, the using class must bind... and the compiler's considering it "protected" otherwise... sigh....
        HeightFieldCPtr         m_heightField;

    protected:
        Url                     m_heightFieldUrl;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AHeightField();
        virtual ~AHeightField();

        virtual void            height_field(emit_k);
        
    private:
        void        on_set_height_field(const SetHeightFieldCommand&);
        void        on_set_height_field_url(const SetHeightFieldUrlCommand&);
        void        on_set_height_field_spec(const SetHeightFieldSpecCommand&);
        
    };

}
