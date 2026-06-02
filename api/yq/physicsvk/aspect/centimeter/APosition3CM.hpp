////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/interface/centimeter/IPosition3CM.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition³CMCommand;
    class AddPositionˣCMCommand;
    class AddPositionʸCMCommand;
    class AddPositionᶻCMCommand;
    class MultiplyPositionDCommand; 
    class MultiplyPosition³DCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class MultiplyPositionᶻDCommand;
    class SetPosition³CMCommand;
    class SetPositionˣCMCommand;
    class SetPositionʸCMCommand;
    class SetPositionᶻCMCommand;

    class APosition³CM : public IPosition³CM, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Centimeter3D    position    = ZERO;
        };
    
        //!  Basic position in the 3D space
        Centimeter3D        position() const override { return m_position; }

        Centimeter           position(x_k) const { return m_position.x; }
        Centimeter           position(y_k) const { return m_position.y; }
        Centimeter           position(z_k) const { return m_position.z; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Centimeter3D&) override;
        void            position(set_k, x_k, Centimeter) override;
        void            position(set_k, y_k, Centimeter) override;
        void            position(set_k, z_k, Centimeter) override;

        //!  Add the position (ie set to position + delta)
        void            position(add_k, const Centimeter3D&) override;
        void            position(add_k, x_k, Centimeter) override;
        void            position(add_k, y_k, Centimeter) override;
        void            position(add_k, z_k, Centimeter) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector3D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        void            position(multiply_k, z_k, double) override;
        
        virtual bool    position(disabled_k) const override { return false; }
        virtual bool    position(settable_k) const override { return true; }
        virtual bool    position(addable_k) const override { return true; }
        virtual bool    position(multipliable_k) const override { return true; }

        const Centimeter3D& position(ref_k) const { return m_position; }

    protected:
        
        Centimeter3D    m_position = ZERO;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition³CM(const Param&);
        APosition³CM(const Centimeter3D& pos=ZERO);
        virtual ~APosition³CM();
        
        void        position(emit_k);

    private:
        void        on_set_position3(const SetPosition³CMCommand&);
        void        on_set_positionX(const SetPositionˣCMCommand&);
        void        on_set_positionY(const SetPositionʸCMCommand&);
        void        on_set_positionZ(const SetPositionᶻCMCommand&);

        void        on_add_position3(const AddPosition³CMCommand&);
        void        on_add_positionX(const AddPositionˣCMCommand&);
        void        on_add_positionY(const AddPositionʸCMCommand&);
        void        on_add_positionZ(const AddPositionᶻCMCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position3(const MultiplyPosition³DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
        void        on_multiply_positionZ(const MultiplyPositionᶻDCommand&);
    };
}
