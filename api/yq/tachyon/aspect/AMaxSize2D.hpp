////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/tachyon/interface/IMaxSize2D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize²DCommand;
    class AddMaxSizeˣDCommand;
    class AddMaxSizeʸDCommand;
    class MultiplyMaxSizeDCommand;
    class MultiplyMaxSize²DCommand;
    class MultiplyMaxSizeˣDCommand;
    class MultiplyMaxSizeʸDCommand;
    class SetMaxSize²DCommand;
    class SetMaxSizeˣDCommand;
    class SetMaxSizeʸDCommand;

    class AMaxSize²D : public IMaxSize²D, public virtual Tachyon::Helper {
    public:
    
        using IMaxSize²D::max_size;
    
        //!  Basic max_size in the 2D space
        Size2D          max_size() const override { return m_max_size; }

        double          max_size(x_k) const { return m_max_size.x; }
        double          max_size(y_k) const { return m_max_size.y; }
        
        //!  SetMax max_size the max_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    max_size(set_k, const Size2D&) override;
        void            max_size(set_k, x_k, double) override;
        void            max_size(set_k, y_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void            max_size(add_k, const Size2D&) override;
        void            max_size(add_k, x_k, double) override;
        void            max_size(add_k, y_k, double) override;

        void            max_size(multiply_k, double) override;
        void            max_size(multiply_k, const Vector2D&) override;
        void            max_size(multiply_k, x_k, double) override;
        void            max_size(multiply_k, y_k, double) override;
        
        bool            max_size(disabled_k) const { return false; }
        bool            max_size(settable_k) const { return true; }
        bool            max_size(addable_k) const { return true; }
        bool            max_size(multipliable_k) const { return true; }

        const Size2D&   max_size(ref_k) const { return m_max_size; }

    protected:
        Size2D      m_max_size = NAN;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMaxSize²D();
        virtual ~AMaxSize²D();

        void        max_size(emit_k);
        
    private:
        void        on_set_max_size2(const SetMaxSize²DCommand&);
        void        on_set_max_sizeX(const SetMaxSizeˣDCommand&);
        void        on_set_max_sizeY(const SetMaxSizeʸDCommand&);

        void        on_add_max_size2(const AddMaxSize²DCommand&);
        void        on_add_max_sizeX(const AddMaxSizeˣDCommand&);
        void        on_add_max_sizeY(const AddMaxSizeʸDCommand&);
        
        void        on_multiply_max_size(const MultiplyMaxSizeDCommand&);
        void        on_multiply_max_size2(const MultiplyMaxSize²DCommand&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣDCommand&);
        void        on_multiply_max_sizeY(const MultiplyMaxSizeʸDCommand&);
    };

}
