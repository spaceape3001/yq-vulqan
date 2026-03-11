////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IPosition1.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition¹DCommand;
    class AddPositionˣDCommand;
    class MultiplyPositionCommand;
    class MultiplyPosition¹DCommand;
    class MultiplyPositionˣDCommand;
    class SetPosition¹DCommand;
    class SetPositionˣDCommand;

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
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition¹();
        virtual ~APosition¹();

        void            position(emit_k);
        
    private:
        void        on_set_position1(const SetPosition¹DCommand&);
        void        on_set_positionX(const SetPositionˣDCommand&);

        void        on_add_position1(const AddPosition¹DCommand&);
        void        on_add_positionX(const AddPositionˣDCommand&);
        
        void        on_multiply_position(const MultiplyPositionCommand&);
        void        on_multiply_position1(const MultiplyPosition¹DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);

    };

}
