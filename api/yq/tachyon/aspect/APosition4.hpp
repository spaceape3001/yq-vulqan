////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IPosition4.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition⁴DCommand;
    class AddPositionʷCommand;
    class AddPositionˣDCommand;
    class AddPositionʸDCommand;
    class AddPositionᶻDCommand;
    class MultiplyPositionCommand;   // here due to copy & paste, however
    class MultiplyPosition⁴DCommand;  // might go for it (later)
    class MultiplyPositionʷCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class MultiplyPositionᶻDCommand;
    class SetPosition⁴DCommand;
    class SetPositionʷDCommand;
    class SetPositionˣDCommand;
    class SetPositionʸDCommand;
    class SetPositionᶻDCommand;

    class APosition⁴ : public IPosition⁴, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 4D space
        Vector4D        position() const override { return m_position; }

        double          position(x_k) const { return m_position.x; }
        double          position(y_k) const { return m_position.y; }
        double          position(z_k) const { return m_position.z; }
        double          position(w_k) const { return m_position.w; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector4D&) override;
        void            position(set_k, x_k, double) override;
        void            position(set_k, y_k, double) override;
        void            position(set_k, z_k, double) override;
        void            position(set_k, w_k, double) override;
        
        //!  Add the position (ie set to position + delta)
        void            position(add_k, const Vector4D&) override;
        void            position(add_k, x_k, double) override;
        void            position(add_k, y_k, double) override;
        void            position(add_k, z_k, double) override;
        void            position(add_k, w_k, double) override;

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

        const Vector4D& position(ref_k) const { return m_position; }

    protected:
        
        Vector4D    m_position = ZERO;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition⁴(const Vector4D& pos=ZERO);
        virtual ~APosition⁴();
        
        void        position(emit_k);

    private:
        void        on_set_position4(const SetPosition⁴DCommand&);
        void        on_set_positionW(const SetPositionʷDCommand&);
        void        on_set_positionX(const SetPositionˣDCommand&);
        void        on_set_positionY(const SetPositionʸDCommand&);
        void        on_set_positionZ(const SetPositionᶻDCommand&);

        void        on_add_position4(const AddPosition⁴DCommand&);
        void        on_add_positionW(const AddPositionʷCommand&);
        void        on_add_positionX(const AddPositionˣDCommand&);
        void        on_add_positionY(const AddPositionʸDCommand&);
        void        on_add_positionZ(const AddPositionᶻDCommand&);
        
        void        on_multiply_position(const MultiplyPositionCommand&);
        void        on_multiply_position4(const MultiplyPosition⁴DCommand&);
        void        on_multiply_positionW(const MultiplyPositionʷCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
        void        on_multiply_positionZ(const MultiplyPositionᶻDCommand&);
    };
}
