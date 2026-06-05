////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/centimeter/IPosition1CM.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition¹CMCommand;
    class AddPositionˣCMCommand;
    class MultiplyPositionDCommand;
    class MultiplyPosition¹DCommand;
    class MultiplyPositionˣDCommand;
    class SetPosition¹CMCommand;
    class SetPositionˣCMCommand;

    class APosition¹CM : public IPosition¹CM, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 1D space
        Centimeter1D    position() const override { return m_position; }

        Centimeter      position(x_k) const { return m_position.x; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Centimeter1D&) override;
        void            position(set_k, x_k, Centimeter) override;
        
        //!  Move the position (ie set to position + delta)
        void            position(add_k, const Centimeter1D&) override;
        void            position(add_k, x_k, Centimeter) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector1D&) override;
        void            position(multiply_k, x_k, double) override;
        
        bool            position(disabled_k) const { return false; }
        bool            position(settable_k) const { return true; }
        bool            position(addable_k) const { return true; }
        bool            position(multipliable_k) const { return true; }

        const Centimeter1D& position(ref_k) const { return m_position; }

    protected:
        
        Centimeter1D    m_position = ZERO;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition¹CM();
        virtual ~APosition¹CM();

        void            position(emit_k);
        
    private:
        void        on_set_position1(const SetPosition¹CMCommand&);
        void        on_set_positionX(const SetPositionˣCMCommand&);

        void        on_add_position1(const AddPosition¹CMCommand&);
        void        on_add_positionX(const AddPositionˣCMCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position1(const MultiplyPosition¹DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);

    };

}
