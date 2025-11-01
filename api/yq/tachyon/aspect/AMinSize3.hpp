////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IMinSize3.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize³Command;
    class AddMinSizeˣCommand;
    class AddMinSizeʸCommand;
    class AddMinSizeᶻCommand;
    class MultiplyMinSize;
    class MultiplyMinSize³Command;
    class MultiplyMinSizeˣCommand;
    class MultiplyMinSizeʸCommand;
    class MultiplyMinSizeᶻCommand;
    class SetMinSize³Command;
    class SetMinSizeˣCommand;
    class SetMinSizeʸCommand;
    class SetMinSizeᶻCommand;

    class AMinSize³ : public IMinSize³, public virtual Tachyon::Helper {
    public:
    
        //!  Basic min_size in the 3D space
        Size3D          min_size() const override { return m_min_size; }
        
        double          min_size(x_k) const { return m_min_size.x; }
        double          min_size(y_k) const { return m_min_size.y; }
        double          min_size(z_k) const { return m_min_size.z; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size3D&) override;
        void            min_size(set_k, x_k, double) override;
        void            min_size(set_k, y_k, double) override;
        void            min_size(set_k, z_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Vector3D&) override;
        void            min_size(add_k, x_k, double) override;
        void            min_size(add_k, y_k, double) override;
        void            min_size(add_k, z_k, double) override;

        void            min_size(multiply_k, double) override;
        void            min_size(multiply_k, const Vector3D&) override;
        void            min_size(multiply_k, x_k, double) override;
        void            min_size(multiply_k, y_k, double) override;
        void            min_size(multiply_k, z_k, double) override;
        
        bool            min_size(disabled_k) const { return false; }
        bool            min_size(settable_k) const { return true; }
        bool            min_size(addable_k) const { return true; }
        bool            min_size(multipliable_k) const { return true; }
        
        const Size3D&   min_size(ref_k) const { return m_min_size; }

    protected:

        Size3D      m_min_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMinSize³();
        virtual ~AMinSize³();
        
        void        min_size(emit_k);
        
    private:
        void        on_set_min_size3(const SetMinSize³Command&);
        void        on_set_min_sizeX(const SetMinSizeˣCommand&);
        void        on_set_min_sizeY(const SetMinSizeʸCommand&);
        void        on_set_min_sizeZ(const SetMinSizeᶻCommand&);

        void        on_add_min_size3(const AddMinSize³Command&);
        void        on_add_min_sizeX(const AddMinSizeˣCommand&);
        void        on_add_min_sizeY(const AddMinSizeʸCommand&);
        void        on_add_min_sizeZ(const AddMinSizeᶻCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSize&);
        void        on_multiply_min_size3(const MultiplyMinSize³Command&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣCommand&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸCommand&);
        void        on_multiply_min_sizeZ(const MultiplyMinSizeᶻCommand&);

    };

}
