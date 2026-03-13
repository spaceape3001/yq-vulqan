////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size4.hpp>
#include <yq/tachyon/interface/IMaxSize4D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize⁴DCommand;
    class AddMaxSizeˣDCommand;
    class AddMaxSizeʷDCommand;
    class AddMaxSizeʸDCommand;
    class AddMaxSizeᶻDCommand;
    class MultiplyMaxSizeDCommand;
    class MultiplyMaxSize⁴DCommand;
    class MultiplyMaxSizeʷDCommand;
    class MultiplyMaxSizeˣDCommand;
    class MultiplyMaxSizeʸDCommand;
    class MultiplyMaxSizeᶻDCommand;
    class SetMaxSize⁴DCommand;
    class SetMaxSizeʷDCommand;
    class SetMaxSizeˣDCommand;
    class SetMaxSizeʸDCommand;
    class SetMaxSizeᶻDCommand;

    class AMaxSize⁴D : public IMaxSize⁴D, public virtual Tachyon::Helper {
    public:
        using IMaxSize⁴D::max_size;
    
        //!  Basic max_size in the 4D space
        Size4D          max_size() const override { return m_max_size; }
        
        double          max_size(x_k) const { return m_max_size.x; }
        double          max_size(y_k) const { return m_max_size.y; }
        double          max_size(z_k) const { return m_max_size.z; }
        double          max_size(w_k) const { return m_max_size.z; }
        
        //!  SetMax max_size the max_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    max_size(set_k, const Size4D&) override;
        void            max_size(set_k, x_k, double) override;
        void            max_size(set_k, y_k, double) override;
        void            max_size(set_k, z_k, double) override;
        void            max_size(set_k, w_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void            max_size(add_k, const Size4D&) override;
        void            max_size(add_k, x_k, double) override;
        void            max_size(add_k, y_k, double) override;
        void            max_size(add_k, z_k, double) override;
        void            max_size(add_k, w_k, double) override;

        void            max_size(multiply_k, double) override;
        void            max_size(multiply_k, const Vector4D&) override;
        void            max_size(multiply_k, x_k, double) override;
        void            max_size(multiply_k, y_k, double) override;
        void            max_size(multiply_k, z_k, double) override;
        void            max_size(multiply_k, w_k, double) override;
        
        bool            max_size(disabled_k) const { return false; }
        bool            max_size(settable_k) const { return true; }
        bool            max_size(addable_k) const { return true; }
        bool            max_size(multipliable_k) const { return true; }
        
        const Size4D&   max_size(ref_k) const { return m_max_size; }

    protected:

        Size4D      m_max_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMaxSize⁴D();
        virtual ~AMaxSize⁴D();
        
        void        max_size(emit_k);
        
    private:
        void        on_set_max_size4(const SetMaxSize⁴DCommand&);
        void        on_set_max_sizeW(const SetMaxSizeʷDCommand&);
        void        on_set_max_sizeX(const SetMaxSizeˣDCommand&);
        void        on_set_max_sizeY(const SetMaxSizeʸDCommand&);
        void        on_set_max_sizeZ(const SetMaxSizeᶻDCommand&);

        void        on_add_max_size4(const AddMaxSize⁴DCommand&);
        void        on_add_max_sizeW(const AddMaxSizeʷDCommand&);
        void        on_add_max_sizeX(const AddMaxSizeˣDCommand&);
        void        on_add_max_sizeY(const AddMaxSizeʸDCommand&);
        void        on_add_max_sizeZ(const AddMaxSizeᶻDCommand&);
        
        void        on_multiply_max_size(const MultiplyMaxSizeDCommand&);
        void        on_multiply_max_size4(const MultiplyMaxSize⁴DCommand&);
        void        on_multiply_max_sizeW(const MultiplyMaxSizeʷDCommand&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&);
        void        on_multiply_max_sizeY(const MultiplyMaxSizeʸDCommand&);
        void        on_multiply_max_sizeZ(const MultiplyMaxSizeᶻDCommand&);

    };

}
