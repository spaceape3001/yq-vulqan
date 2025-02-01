////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IPosition1.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition¹;
    class AddPositionˣ;
    class MultiplyPosition;
    class MultiplyPosition¹;
    class MultiplyPositionˣ;
    class SetPosition¹;
    class SetPositionˣ;

    class APosition¹ : public IPosition¹, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 1D space
        Vector1D        position() const override { return m_position; }

        double          position(x_k) const { return m_position.x; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector1D&) override;
        void            position(set_k, x_k, double) override;
        
        //!  Move the position (ie set to position + delta)
        void            position(add_k, const Vector1D&) override;
        void            position(add_k, x_k, double) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector1D&) override;
        void            position(multiply_k, x_k, double) override;
        
        bool            position(disabled_k) const { return false; }
        bool            position(settable_k) const { return true; }
        bool            position(addable_k) const { return true; }
        bool            position(multipliable_k) const { return true; }

        const Vector1D& position(ref_k) const { return m_position; }

    protected:
        
        Vector1D    m_position = ZERO;
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        APosition¹();
        virtual ~APosition¹();

        void            position(emit_k);
        
    private:
        void        on_set_position1(const SetPosition¹&);
        void        on_set_positionX(const SetPositionˣ&);

        void        on_add_position1(const AddPosition¹&);
        void        on_add_positionX(const AddPositionˣ&);
        
        void        on_multiply_position(const MultiplyPosition&);
        void        on_multiply_position1(const MultiplyPosition¹&);
        void        on_multiply_positionX(const MultiplyPositionˣ&);

    };

}
