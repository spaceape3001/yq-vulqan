////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size1.hpp>
#include <yq/tachyon/interface/IMinSize1D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize¹DCommand;
    class AddMinSizeˣDCommand;
    class MultiplyMinSizeDCommand;
    class MultiplyMinSize¹DCommand;
    class MultiplyMinSizeˣDCommand;
    class SetMinSize¹DCommand;
    class SetMinSizeˣDCommand;

    class AMinSize¹D : public IMinSize¹D, public virtual Tachyon::Helper {
    public:
    
        using IMinSize¹D::min_size;
    
        //!  Basic min_size in the 1D space
        Size1D          min_size() const override { return m_min_size; }
        double          min_size(x_k) const { return m_min_size.x; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size1D&) override;
        void            min_size(set_k, x_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Size1D&) override;
        void            min_size(add_k, x_k, double) override;

        void            min_size(multiply_k, double) override;
        void            min_size(multiply_k, const Vector1D&) override;
        void            min_size(multiply_k, x_k, double) override;
        
        bool            min_size(disabled_k) const { return false; }
        bool            min_size(settable_k) const { return true; }
        bool            min_size(addable_k) const { return true; }
        bool            min_size(multipliable_k) const { return true; }

        const Size1D&   min_size(ref_k) const { return m_min_size; }

    protected:
        Size1D      m_min_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMinSize¹D();
        virtual ~AMinSize¹D();

        void        min_size(emit_k);
        
    private:
        void        on_set_min_size1(const SetMinSize¹DCommand&);
        void        on_set_min_sizeX(const SetMinSizeˣDCommand&);

        void        on_add_min_size1(const AddMinSize¹DCommand&);
        void        on_add_min_sizeX(const AddMinSizeˣDCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSizeDCommand&);
        void        on_multiply_min_size1(const MultiplyMinSize¹DCommand&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&);
    };
}
