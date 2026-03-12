////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IMaxSize1.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize¹DCommand;
    class AddMaxSizeˣDCommand;
    class MultiplyMaxSizeDCommand;
    class MultiplyMaxSize¹DCommand;
    class MultiplyMaxSizeˣDCommand;
    class SetMaxSize¹DCommand;
    class SetMaxSizeˣDCommand;

    class AMaxSize¹ : public IMaxSize¹, public virtual Tachyon::Helper {
    public:
    
        //!  Basic max_size in the 1D space
        Size1D          max_size() const override { return m_max_size; }
        double          max_size(x_k) const { return m_max_size.x; }
        
        //!  SetMax max_size the max_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    max_size(set_k, const Size1D&) override;
        void            max_size(set_k, x_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void            max_size(add_k, const Size1D&) override;
        void            max_size(add_k, x_k, double) override;

        void            max_size(multiply_k, double) override;
        void            max_size(multiply_k, const Vector1D&) override;
        void            max_size(multiply_k, x_k, double) override;
        
        bool            max_size(disabled_k) const { return false; }
        bool            max_size(settable_k) const { return true; }
        bool            max_size(addable_k) const { return true; }
        bool            max_size(multipliable_k) const { return true; }

        const Size1D&   max_size(ref_k) const { return m_max_size; }

    protected:
        Size1D      m_max_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMaxSize¹();
        virtual ~AMaxSize¹();

        void        max_size(emit_k);
        
    private:
        void        on_set_max_size1(const SetMaxSize¹DCommand&);
        void        on_set_max_sizeX(const SetMaxSizeˣDCommand&);

        void        on_add_max_size1(const AddMaxSize¹DCommand&);
        void        on_add_max_sizeX(const AddMaxSizeˣDCommand&);
        
        void        on_multiply_max_size(const MultiplyMaxSizeDCommand&);
        void        on_multiply_max_size1(const MultiplyMaxSize¹DCommand&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&);
    };
}
