////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/interface/meter/IPosition3M.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition³MCommand;
    class AddPositionˣMCommand;
    class AddPositionʸMCommand;
    class AddPositionᶻMCommand;
    class MultiplyPositionDCommand; 
    class MultiplyPosition³DCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class MultiplyPositionᶻDCommand;
    class SetPosition³MCommand;
    class SetPositionˣMCommand;
    class SetPositionʸMCommand;
    class SetPositionᶻMCommand;

    class APosition³M : public IPosition³M, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector3M    position    = ZERO;
        };
    
        //!  Basic position in the 3D space
        Vector3M        position() const override { return m_position; }

        Meter           position(x_k) const { return m_position.x; }
        Meter           position(y_k) const { return m_position.y; }
        Meter           position(z_k) const { return m_position.z; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector3M&) override;
        void            position(set_k, x_k, Meter) override;
        void            position(set_k, y_k, Meter) override;
        void            position(set_k, z_k, Meter) override;

        //!  Add the position (ie set to position + delta)
        void            position(add_k, const Vector3M&) override;
        void            position(add_k, x_k, Meter) override;
        void            position(add_k, y_k, Meter) override;
        void            position(add_k, z_k, Meter) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector3D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        void            position(multiply_k, z_k, double) override;
        
        virtual bool    position(disabled_k) const override { return false; }
        virtual bool    position(settable_k) const override { return true; }
        virtual bool    position(addable_k) const override { return true; }
        virtual bool    position(multipliable_k) const override { return true; }

        const Vector3M& position(ref_k) const { return m_position; }

    protected:
        
        Vector3M    m_position = ZERO;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition³M(const Param&);
        APosition³M(const Vector3M& pos=ZERO);
        virtual ~APosition³M();
        
        void        position(emit_k);

    private:
        void        on_set_position3(const SetPosition³MCommand&);
        void        on_set_positionX(const SetPositionˣMCommand&);
        void        on_set_positionY(const SetPositionʸMCommand&);
        void        on_set_positionZ(const SetPositionᶻMCommand&);

        void        on_add_position3(const AddPosition³MCommand&);
        void        on_add_positionX(const AddPositionˣMCommand&);
        void        on_add_positionY(const AddPositionʸMCommand&);
        void        on_add_positionZ(const AddPositionᶻMCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position3(const MultiplyPosition³DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
        void        on_multiply_positionZ(const MultiplyPositionᶻDCommand&);
    };
}
