////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/tachyon/interface/IMinSize2D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize²DCommand;
    class AddMinSizeˣDCommand;
    class AddMinSizeʸDCommand;
    class MultiplyMinSizeDCommand;
    class MultiplyMinSize²DCommand;
    class MultiplyMinSizeˣDCommand;
    class MultiplyMinSizeʸDCommand;
    class SetMinSize²DCommand;
    class SetMinSizeˣDCommand;
    class SetMinSizeʸDCommand;

    class AMinSize²D : public IMinSize²D, public virtual Tachyon::Helper {
    public:
    
        using IMinSize²D::min_size;
    
        //!  Basic min_size in the 2D space
        Size2D          min_size() const override { return m_min_size; }

        double          min_size(x_k) const { return m_min_size.x; }
        double          min_size(y_k) const { return m_min_size.y; }
        
        //!  SetMin min_size the min_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    min_size(set_k, const Size2D&) override;
        void            min_size(set_k, x_k, double) override;
        void            min_size(set_k, y_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void            min_size(add_k, const Size2D&) override;
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
        
        AMinSize²D();
        virtual ~AMinSize²D();

        void        min_size(emit_k);
        
    private:
        void        on_set_min_size2(const SetMinSize²DCommand&);
        void        on_set_min_sizeX(const SetMinSizeˣDCommand&);
        void        on_set_min_sizeY(const SetMinSizeʸDCommand&);

        void        on_add_min_size2(const AddMinSize²DCommand&);
        void        on_add_min_sizeX(const AddMinSizeˣDCommand&);
        void        on_add_min_sizeY(const AddMinSizeʸDCommand&);
        
        void        on_multiply_min_size(const MultiplyMinSizeDCommand&);
        void        on_multiply_min_size2(const MultiplyMinSize²DCommand&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣDCommand&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸDCommand&);
    };

}
