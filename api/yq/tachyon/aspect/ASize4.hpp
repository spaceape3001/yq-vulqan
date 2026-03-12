////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ISize4.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize⁴DCommand;
    class AddSizeʷDCommand;
    class AddSizeˣDCommand;
    class AddSizeʸDCommand;
    class AddSizeᶻDCommand;
    class MultiplySizeDCommand;
    class MultiplySize⁴DCommand;
    class MultiplySizeʷDCommand;
    class MultiplySizeˣDCommand;
    class MultiplySizeʸDCommand;
    class MultiplySizeᶻDCommand;
    class SetSize⁴DCommand;
    class SetSizeʷDCommand;
    class SetSizeˣDCommand;
    class SetSizeʸDCommand;
    class SetSizeᶻDCommand;

    class ASize⁴ : public ISize⁴, public virtual Tachyon::Helper {
    public:
    
        //!  Basic size in the 4D space
        Size4D          size() const override { return m_size; }
        
        double          size(x_k) const { return m_size.x; }
        double          size(y_k) const { return m_size.y; }
        double          size(z_k) const { return m_size.z; }
        double          size(w_k) const { return m_size.w; }
        
        //!  Set size the size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    size(set_k, const Size4D&) override;
        void            size(set_k, x_k, double) override;
        void            size(set_k, y_k, double) override;
        void            size(set_k, z_k, double) override;
        void            size(set_k, w_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void            size(add_k, const Vector4D&) override;
        void            size(add_k, x_k, double) override;
        void            size(add_k, y_k, double) override;
        void            size(add_k, z_k, double) override;
        void            size(add_k, w_k, double) override;

        void            size(multiply_k, double) override;
        void            size(multiply_k, const Vector4D&) override;
        void            size(multiply_k, x_k, double) override;
        void            size(multiply_k, y_k, double) override;
        void            size(multiply_k, z_k, double) override;
        void            size(multiply_k, w_k, double) override;
        
        bool            size(disabled_k) const { return false; }
        bool            size(settable_k) const { return true; }
        bool            size(addable_k) const { return true; }
        bool            size(multipliable_k) const { return true; }
        
        const Size4D&   size(ref_k) const { return m_size; }

    protected:

        Size4D      m_size = ONE;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ASize⁴();
        virtual ~ASize⁴();
        
        void        size(emit_k);
        
    private:
        void        on_set_size4(const SetSize⁴DCommand&);
        void        on_set_sizeW(const SetSizeʷDCommand&);
        void        on_set_sizeX(const SetSizeˣDCommand&);
        void        on_set_sizeY(const SetSizeʸDCommand&);
        void        on_set_sizeZ(const SetSizeᶻDCommand&);

        void        on_add_size4(const AddSize⁴DCommand&);
        void        on_add_sizeW(const AddSizeʷDCommand&);
        void        on_add_sizeX(const AddSizeˣDCommand&);
        void        on_add_sizeY(const AddSizeʸDCommand&);
        void        on_add_sizeZ(const AddSizeᶻDCommand&);
        
        void        on_multiply_size(const MultiplySizeDCommand&);
        void        on_multiply_size4(const MultiplySize⁴DCommand&);
        void        on_multiply_sizeW(const MultiplySizeʷDCommand&);
        void        on_multiply_sizeX(const MultiplySizeˣDCommand&);
        void        on_multiply_sizeY(const MultiplySizeʸDCommand&);
        void        on_multiply_sizeZ(const MultiplySizeᶻDCommand&);

    };

}
