////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IMinSize4.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize⁴DCommand;
    class AddMinSizeʷDCommand;
    class AddMinSizeˣDCommand;
    class AddMinSizeʸDCommand;
    class AddMinSizeᶻDCommand;
    class MultiplyMinSizeDCommand;
    class MultiplyMinSize⁴DCommand;
    class MultiplyMinSizeʷDCommand;
    class MultiplyMinSizeˣDCommand;
    class MultiplyMinSizeʸDCommand;
    class MultiplyMinSizeᶻDCommand;
    class SetMinSize⁴DCommand;
    class SetMinSizeʷDCommand;
    class SetMinSizeˣDCommand;
    class SetMinSizeʸDCommand;
    class SetMinSizeᶻDCommand;

    class AMinSize⁴ : public IMinSize⁴, public virtual Tachyon::Helper {
    public:
    
        //!  Basic min_size in the 4D space
        Size4D          min_size() const override { return m_min_size; }
        
        double          min_size(x_k) const { return m_min_size.x; }
        double          min_size(y_k) const { return m_min_size.y; }
        double          min_size(z_k) const { return m_min_size.z; }
        double          min_size(w_k) const { return m_min_size.w; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size4D&) override;
        void            min_size(set_k, x_k, double) override;
        void            min_size(set_k, y_k, double) override;
        void            min_size(set_k, z_k, double) override;
        void            min_size(set_k, w_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Vector4D&) override;
        void            min_size(add_k, x_k, double) override;
        void            min_size(add_k, y_k, double) override;
        void            min_size(add_k, z_k, double) override;
        void            min_size(add_k, w_k, double) override;

        void            min_size(multiply_k, double) override;
        void            min_size(multiply_k, const Vector4D&) override;
        void            min_size(multiply_k, x_k, double) override;
        void            min_size(multiply_k, y_k, double) override;
        void            min_size(multiply_k, z_k, double) override;
        void            min_size(multiply_k, w_k, double) override;
        
        bool            min_size(disabled_k) const { return false; }
        bool            min_size(settable_k) const { return true; }
        bool            min_size(addable_k) const { return true; }
        bool            min_size(multipliable_k) const { return true; }
        
        const Size4D&   min_size(ref_k) const { return m_min_size; }

    protected:

        Size4D      m_min_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMinSize⁴();
        virtual ~AMinSize⁴();
        
        void        min_size(emit_k);
        
    private:
        void        on_set_min_size4(const SetMinSize⁴DCommand&);
        void        on_set_min_sizeW(const SetMinSizeʷDCommand&);
        void        on_set_min_sizeX(const SetMinSizeˣDCommand&);
        void        on_set_min_sizeY(const SetMinSizeʸDCommand&);
        void        on_set_min_sizeZ(const SetMinSizeᶻDCommand&);

        void        on_add_min_size4(const AddMinSize⁴DCommand&);
        void        on_add_min_sizeW(const AddMinSizeʷDCommand&);
        void        on_add_min_sizeX(const AddMinSizeˣDCommand&);
        void        on_add_min_sizeY(const AddMinSizeʸDCommand&);
        void        on_add_min_sizeZ(const AddMinSizeᶻDCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSizeDCommand&);
        void        on_multiply_min_size4(const MultiplyMinSize⁴DCommand&);
        void        on_multiply_min_sizeW(const MultiplyMinSizeʷDCommand&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸDCommand&);
        void        on_multiply_min_sizeZ(const MultiplyMinSizeᶻDCommand&);

    };

}
