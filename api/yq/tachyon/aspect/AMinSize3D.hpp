////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size3.hpp>
#include <yq/tachyon/interface/IMinSize3D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize³DCommand;
    class AddMinSizeˣDCommand;
    class AddMinSizeʸDCommand;
    class AddMinSizeᶻDCommand;
    class MultiplyMinSizeDCommand;
    class MultiplyMinSize³DCommand;
    class MultiplyMinSizeˣDCommand;
    class MultiplyMinSizeʸDCommand;
    class MultiplyMinSizeᶻDCommand;
    class SetMinSize³DCommand;
    class SetMinSizeˣDCommand;
    class SetMinSizeʸDCommand;
    class SetMinSizeᶻDCommand;

    class AMinSize³D : public IMinSize³D, public virtual Tachyon::Helper {
    public:
    
        using IMinSize³D::min_size;
    
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
        void            min_size(add_k, const Size3D&) override;
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
        
        AMinSize³D();
        virtual ~AMinSize³D();
        
        void        min_size(emit_k);
        
    private:
        void        on_set_min_size3(const SetMinSize³DCommand&);
        void        on_set_min_sizeX(const SetMinSizeˣDCommand&);
        void        on_set_min_sizeY(const SetMinSizeʸDCommand&);
        void        on_set_min_sizeZ(const SetMinSizeᶻDCommand&);

        void        on_add_min_size3(const AddMinSize³DCommand&);
        void        on_add_min_sizeX(const AddMinSizeˣDCommand&);
        void        on_add_min_sizeY(const AddMinSizeʸDCommand&);
        void        on_add_min_sizeZ(const AddMinSizeᶻDCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSizeDCommand&);
        void        on_multiply_min_size3(const MultiplyMinSize³DCommand&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸDCommand&);
        void        on_multiply_min_sizeZ(const MultiplyMinSizeᶻDCommand&);

    };

}
