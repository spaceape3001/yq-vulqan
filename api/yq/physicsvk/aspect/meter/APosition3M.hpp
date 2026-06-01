////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IPosition3D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition³DCommand;
    class AddPositionˣDCommand;
    class AddPositionʸDCommand;
    class AddPositionᶻDCommand;
    class MultiplyPositionDCommand; 
    class MultiplyPosition³DCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class MultiplyPositionᶻDCommand;
    class SetPosition³DCommand;
    class SetPositionˣDCommand;
    class SetPositionʸDCommand;
    class SetPositionᶻDCommand;

    class APosition³D : public IPosition³D, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector3D    position    = ZERO;
        };
    
        //!  Basic position in the 3D space
        Vector3D        position() const override { return m_position; }

        double          position(x_k) const { return m_position.x; }
        double          position(y_k) const { return m_position.y; }
        double          position(z_k) const { return m_position.z; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector3D&) override;
        void            position(set_k, x_k, double) override;
        void            position(set_k, y_k, double) override;
        void            position(set_k, z_k, double) override;
        
        //!  Add the position (ie set to position + delta)
        void            position(add_k, const Vector3D&) override;
        void            position(add_k, x_k, double) override;
        void            position(add_k, y_k, double) override;
        void            position(add_k, z_k, double) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector3D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        void            position(multiply_k, z_k, double) override;
        
        virtual bool    position(disabled_k) const override { return false; }
        virtual bool    position(settable_k) const override { return true; }
        virtual bool    position(addable_k) const override { return true; }
        virtual bool    position(multipliable_k) const override { return true; }

        const Vector3D& position(ref_k) const { return m_position; }

    protected:
        
        Vector3D    m_position = ZERO;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition³D(const Param&);
        APosition³D(const Vector3D& pos=ZERO);
        virtual ~APosition³D();
        
        void        position(emit_k);

    private:
        void        on_set_position3(const SetPosition³DCommand&);
        void        on_set_positionX(const SetPositionˣDCommand&);
        void        on_set_positionY(const SetPositionʸDCommand&);
        void        on_set_positionZ(const SetPositionᶻDCommand&);

        void        on_add_position3(const AddPosition³DCommand&);
        void        on_add_positionX(const AddPositionˣDCommand&);
        void        on_add_positionY(const AddPositionʸDCommand&);
        void        on_add_positionZ(const AddPositionᶻDCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position3(const MultiplyPosition³DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
        void        on_multiply_positionZ(const MultiplyPositionᶻDCommand&);
    };
}
