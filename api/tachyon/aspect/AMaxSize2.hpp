////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IMaxSize2.hpp>
#include <tachyon/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize²Command;
    class AddMaxSizeˣCommand;
    class AddMaxSizeʸCommand;
    class MultiplyMaxSize;
    class MultiplyMaxSize²Command;
    class MultiplyMaxSizeˣCommand;
    class MultiplyMaxSizeʸCommand;
    class SetMaxSize²Command;
    class SetMaxSizeˣCommand;
    class SetMaxSizeʸCommand;

    class AMaxSize² : public IMaxSize², public virtual Tachyon::Helper {
    public:
    
        //!  Basic max_size in the 2D space
        Size2D          max_size() const override { return m_max_size; }

        double          max_size(x_k) const { return m_max_size.x; }
        double          max_size(y_k) const { return m_max_size.y; }
        
        //!  SetMax max_size the max_size (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    max_size(set_k, const Size2D&) override;
        void            max_size(set_k, x_k, double) override;
        void            max_size(set_k, y_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void            max_size(add_k, const Vector2D&) override;
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
        static void init_info(TachyonMeta::Writer<C>&);
        
        AMaxSize²();
        virtual ~AMaxSize²();

        void        max_size(emit_k);
        
    private:
        void        on_set_max_size2(const SetMaxSize²Command&);
        void        on_set_max_sizeX(const SetMaxSizeˣCommand&);
        void        on_set_max_sizeY(const SetMaxSizeʸCommand&);

        void        on_add_max_size2(const AddMaxSize²Command&);
        void        on_add_max_sizeX(const AddMaxSizeˣCommand&);
        void        on_add_max_sizeY(const AddMaxSizeʸCommand&);
        
        void        on_multiply_max_size(const MultiplyMaxSize&);
        void        on_multiply_max_size2(const MultiplyMaxSize²Command&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣCommand&);
        void        on_multiply_max_sizeY(const MultiplyMaxSizeʸCommand&);
    };

}
