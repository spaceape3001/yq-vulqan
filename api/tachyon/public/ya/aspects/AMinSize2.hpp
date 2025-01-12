////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IMinSize2.hpp>
#include <yt/api/Tachyon.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {

    class AddMinSize²;
    class AddMinSizeˣ;
    class AddMinSizeʸ;
    class MultiplyMinSize;
    class MultiplyMinSize²;
    class MultiplyMinSizeˣ;
    class MultiplyMinSizeʸ;
    class SetMinSize²;
    class SetMinSizeˣ;
    class SetMinSizeʸ;

    class AMinSize² : public IMinSize², private Tachyon::Helper {
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
        static void init_info(TachyonInfo::Writer<C>&);
        
        AMinSize²();
        virtual ~AMinSize²();

        void        min_size(emit_k);
        
    private:
        void        on_set_min_size2(const SetMinSize²&);
        void        on_set_min_sizeX(const SetMinSizeˣ&);
        void        on_set_min_sizeY(const SetMinSizeʸ&);

        void        on_add_min_size2(const AddMinSize²&);
        void        on_add_min_sizeX(const AddMinSizeˣ&);
        void        on_add_min_sizeY(const AddMinSizeʸ&);
        
        void        on_multiply_min_size(const MultiplyMinSize&);
        void        on_multiply_min_size2(const MultiplyMinSize²&);
        void        on_multiply_min_sizeX(const MultiplyMinSizeˣ&);
        void        on_multiply_min_sizeY(const MultiplyMinSizeʸ&);
    };

}
