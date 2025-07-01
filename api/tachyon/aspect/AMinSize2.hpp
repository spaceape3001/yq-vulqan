////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IMinSize2.hpp>
#include <tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize²Command;
    class AddMinSizeˣCommand;
    class AddMinSizeʸCommand;
    class MultiplyMinSize;
    class MultiplyMinSize²Command;
    class MultiplyMinSizeˣCommand;
    class MultiplyMinSizeʸCommand;
    class SetMinSize²Command;
    class SetMinSizeˣCommand;
    class SetMinSizeʸCommand;

    class AMinSize² : public IMinSize², public virtual Tachyon::Helper {
    public:
    
        //!  Basic min_size in the 2D space
        Size2D          min_size() const override { return m_min_size; }

        double          min_size(x_k) const { return m_min_size.x; }
        double          min_size(y_k) const { return m_min_size.y; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size2D&) override;
        void            min_size(set_k, x_k, double) override;
        void            min_size(set_k, y_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Vector2D&) override;
        void            min_size(add_k, x_k, double) override;
        void            min_size(add_k, y_k, double) override;

        void            min_size(multiply_k, double) override;
        void            min_size(multiply_k, const Vector2D&) override;
        void            min_size(multiply_k, x_k, double) override;
        void            min_size(multiply_k, y_k, double) override;
        
        bool            min_size(disabled_k) const { return false; }
        bool            min_size(settable_k) const { return true; }
        bool            min_size(addable_k) const { return true; }
        bool            min_size(multipliable_k) const { return true; }

        const Size2D&   min_size(ref_k) const { return m_min_size; }

    protected:
        Size2D      m_min_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMinSize²();
        virtual ~AMinSize²();

        void        min_size(emit_k);
        
    private:
        void        on_set_min_size2(const SetMinSize²Command&);
        void        on_set_min_sizeX(const SetMinSizeˣCommand&);
        void        on_set_min_sizeY(const SetMinSizeʸCommand&);

        void        on_add_min_size2(const AddMinSize²Command&);
        void        on_add_min_sizeX(const AddMinSizeˣCommand&);
        void        on_add_min_sizeY(const AddMinSizeʸCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSize&);
        void        on_multiply_min_size2(const MultiplyMinSize²Command&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣCommand&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸCommand&);
    };

}
