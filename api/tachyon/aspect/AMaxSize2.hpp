////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IMaxSize2.hpp>
#include <yt/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMaxSize²;
    class AddMaxSizeˣ;
    class AddMaxSizeʸ;
    class MultiplyMaxSize;
    class MultiplyMaxSize²;
    class MultiplyMaxSizeˣ;
    class MultiplyMaxSizeʸ;
    class SetMaxSize²;
    class SetMaxSizeˣ;
    class SetMaxSizeʸ;

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
        static void init_info(TachyonInfo::Writer<C>&);
        
        AMaxSize²();
        virtual ~AMaxSize²();

        void        max_size(emit_k);
        
    private:
        void        on_set_max_size2(const SetMaxSize²&);
        void        on_set_max_sizeX(const SetMaxSizeˣ&);
        void        on_set_max_sizeY(const SetMaxSizeʸ&);

        void        on_add_max_size2(const AddMaxSize²&);
        void        on_add_max_sizeX(const AddMaxSizeˣ&);
        void        on_add_max_sizeY(const AddMaxSizeʸ&);
        
        void        on_multiply_max_size(const MultiplyMaxSize&);
        void        on_multiply_max_size2(const MultiplyMaxSize²&);
        void        on_multiply_max_sizeX(const MultiplyMaxSizeˣ&);
        void        on_multiply_max_sizeY(const MultiplyMaxSizeʸ&);
    };

}
