////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/centimeter/IPosition4CM.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition⁴CMCommand;
    class AddPositionʷCMCommand;
    class AddPositionˣCMCommand;
    class AddPositionʸCMCommand;
    class AddPositionᶻCMCommand;
    class MultiplyPositionDCommand;   // here due to copy & paste, however
    class MultiplyPosition⁴DCommand;  // might go for it (later)
    class MultiplyPositionʷDCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class MultiplyPositionᶻDCommand;
    class SetPosition⁴CMCommand;
    class SetPositionʷCMCommand;
    class SetPositionˣCMCommand;
    class SetPositionʸCMCommand;
    class SetPositionᶻCMCommand;

    class APosition⁴CM : public IPosition⁴CM, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 4D space
        Centimeter4D        position() const override { return m_position; }

        Centimeter           position(x_k) const { return m_position.x; }
        Centimeter           position(y_k) const { return m_position.y; }
        Centimeter           position(z_k) const { return m_position.z; }
        Centimeter           position(w_k) const { return m_position.w; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Centimeter4D&) override;
        void            position(set_k, x_k, Centimeter) override;
        void            position(set_k, y_k, Centimeter) override;
        void            position(set_k, z_k, Centimeter) override;
        void            position(set_k, w_k, Centimeter) override;
        
        //!  Add the position (ie set to position + delta)
        void            position(add_k, const Centimeter4D&) override;
        void            position(add_k, x_k, Centimeter) override;
        void            position(add_k, y_k, Centimeter) override;
        void            position(add_k, z_k, Centimeter) override;
        void            position(add_k, w_k, Centimeter) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector4D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        void            position(multiply_k, z_k, double) override;
        void            position(multiply_k, w_k, double) override;
        
        virtual bool    position(disabled_k) const override { return false; }
        virtual bool    position(settable_k) const override { return true; }
        virtual bool    position(addable_k) const override { return true; }
        virtual bool    position(multipliable_k) const override { return true; }

        const Centimeter4D& position(ref_k) const { return m_position; }

    protected:
        
        Centimeter4D    m_position = ZERO;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition⁴CM(const Centimeter4D& pos=ZERO);
        virtual ~APosition⁴CM();
        
        void        position(emit_k);

    private:
        void        on_set_position4(const SetPosition⁴CMCommand&);
        void        on_set_positionW(const SetPositionʷCMCommand&);
        void        on_set_positionX(const SetPositionˣCMCommand&);
        void        on_set_positionY(const SetPositionʸCMCommand&);
        void        on_set_positionZ(const SetPositionᶻCMCommand&);

        void        on_add_position4(const AddPosition⁴CMCommand&);
        void        on_add_positionW(const AddPositionʷCMCommand&);
        void        on_add_positionX(const AddPositionˣCMCommand&);
        void        on_add_positionY(const AddPositionʸCMCommand&);
        void        on_add_positionZ(const AddPositionᶻCMCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position4(const MultiplyPosition⁴DCommand&);
        void        on_multiply_positionW(const MultiplyPositionʷDCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
        void        on_multiply_positionZ(const MultiplyPositionᶻDCommand&);
    };
}
