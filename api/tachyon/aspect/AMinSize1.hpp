////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IMinSize1.hpp>
#include <tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize¹Command;
    class AddMinSizeˣCommand;
    class MultiplyMinSize;
    class MultiplyMinSize¹Command;
    class MultiplyMinSizeˣCommand;
    class SetMinSize¹Command;
    class SetMinSizeˣCommand;

    class AMinSize¹ : public IMinSize¹, public virtual Tachyon::Helper {
    public:
    
        //!  Basic min_size in the 1D space
        Size1D          min_size() const override { return m_min_size; }
        double          min_size(x_k) const { return m_min_size.x; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size1D&) override;
        void            min_size(set_k, x_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Vector1D&) override;
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
        static void init_info(TachyonMeta::Writer<C>&);
        
        AMinSize¹();
        virtual ~AMinSize¹();

        void        min_size(emit_k);
        
    private:
        void        on_set_min_size1(const SetMinSize¹Command&);
        void        on_set_min_sizeX(const SetMinSizeˣCommand&);

        void        on_add_min_size1(const AddMinSize¹Command&);
        void        on_add_min_sizeX(const AddMinSizeˣCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSize&);
        void        on_multiply_min_size1(const MultiplyMinSize¹Command&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣCommand&);
    };
}
