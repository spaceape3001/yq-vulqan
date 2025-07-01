////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/ISize2.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize²Command;
    class AddSizeˣCommand;
    class AddSizeʸCommand;
    class MultiplySize;
    class MultiplySize²Command;
    class MultiplySizeˣCommand;
    class MultiplySizeʸCommand;
    class SetSize²Command;
    class SetSizeˣCommand;
    class SetSizeʸCommand;

    class ASize² : public ISize², public virtual Tachyon::Helper {
    public:
    
        //!  Basic size in the 2D space
        Size2D          size() const override { return m_size; }

        double          size(x_k) const { return m_size.x; }
        double          size(y_k) const { return m_size.y; }
        
        //!  Set size the size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    size(set_k, const Size2D&) override;
        void            size(set_k, x_k, double) override;
        void            size(set_k, y_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void            size(add_k, const Vector2D&) override;
        void            size(add_k, x_k, double) override;
        void            size(add_k, y_k, double) override;

        void            size(multiply_k, double) override;
        void            size(multiply_k, const Vector2D&) override;
        void            size(multiply_k, x_k, double) override;
        void            size(multiply_k, y_k, double) override;
        
        bool            size(disabled_k) const { return false; }
        bool            size(settable_k) const { return true; }
        bool            size(addable_k) const { return true; }
        bool            size(multipliable_k) const { return true; }

        const Size2D&   size(ref_k) const { return m_size; }

    protected:
        Size2D      m_size = ONE;
        
        template <typename C>
        static void init_info(TachyonMeta::Writer<C>&);
        
        ASize²();
        virtual ~ASize²();

        void        size(emit_k);
        
    private:
        void        on_set_size2(const SetSize²Command&);
        void        on_set_sizeX(const SetSizeˣCommand&);
        void        on_set_sizeY(const SetSizeʸCommand&);

        void        on_add_size2(const AddSize²Command&);
        void        on_add_sizeX(const AddSizeˣCommand&);
        void        on_add_sizeY(const AddSizeʸCommand&);
        
        void        on_multiply_size(const MultiplySize&);
        void        on_multiply_size2(const MultiplySize²Command&);
        void        on_multiply_sizeX(const MultiplySizeˣCommand&);
        void        on_multiply_sizeY(const MultiplySizeʸCommand&);
    };

}
