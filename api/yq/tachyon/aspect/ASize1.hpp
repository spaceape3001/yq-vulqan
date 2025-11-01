////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ISize1.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize¹Command;
    class AddSizeˣCommand;
    class MultiplySize;
    class MultiplySize¹Command;
    class MultiplySizeˣCommand;
    class SetSize¹Command;
    class SetSizeˣCommand;

    class ASize¹ : public ISize¹, public virtual Tachyon::Helper {
    public:
    
        //!  Basic size in the 1D space
        Size1D          size() const override { return m_size; }
        double          size(x_k) const { return m_size.x; }
        
        //!  Set size the size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    size(set_k, const Size1D&) override;
        void            size(set_k, x_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void            size(add_k, const Vector1D&) override;
        void            size(add_k, x_k, double) override;

        void            size(multiply_k, double) override;
        void            size(multiply_k, const Vector1D&) override;
        void            size(multiply_k, x_k, double) override;
        
        bool            size(disabled_k) const { return false; }
        bool            size(settable_k) const { return true; }
        bool            size(addable_k) const { return true; }
        bool            size(multipliable_k) const { return true; }

        const Size1D&   size(ref_k) const { return m_size; }

    protected:
        Size1D      m_size = ONE;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ASize¹();
        virtual ~ASize¹();

        void        size(emit_k);
        
    private:
        void        on_set_size1(const SetSize¹Command&);
        void        on_set_sizeX(const SetSizeˣCommand&);

        void        on_add_size1(const AddSize¹Command&);
        void        on_add_sizeX(const AddSizeˣCommand&);
        
        void        on_multiply_size(const MultiplySize&);
        void        on_multiply_size1(const MultiplySize¹Command&);
        void        on_multiply_sizeX(const MultiplySizeˣCommand&);
    };
}
