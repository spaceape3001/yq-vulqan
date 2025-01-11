////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/ISize2.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddSize²;
    class AddSizeˣ;
    class AddSizeʸ;
    class MultiplySize;
    class MultiplySize²;
    class MultiplySizeˣ;
    class MultiplySizeʸ;
    class SetSize²;
    class SetSizeˣ;
    class SetSizeʸ;

    class ASize² : public ISize², private Tachyon::Helper {
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
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        ASize²();
        virtual ~ASize²();
        
    private:
        void        on_set_size2(const SetSize²&);
        void        on_set_sizeX(const SetSizeˣ&);
        void        on_set_sizeY(const SetSizeʸ&);

        void        on_add_size2(const AddSize²&);
        void        on_add_sizeX(const AddSizeˣ&);
        void        on_add_sizeY(const AddSizeʸ&);
        
        void        on_multiply_size(const MultiplySize&);
        void        on_multiply_size2(const MultiplySize²&);
        void        on_multiply_sizeX(const MultiplySizeˣ&);
        void        on_multiply_sizeY(const MultiplySizeʸ&);

        Size2D      m_size = ONE;
    };

}
