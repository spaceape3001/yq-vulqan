////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/meter/IPosition1M.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition¹MCommand;
    class AddPositionˣMCommand;
    class MultiplyPositionDCommand;
    class MultiplyPosition¹DCommand;
    class MultiplyPositionˣDCommand;
    class SetPosition¹MCommand;
    class SetPositionˣMCommand;

    class APosition¹M : public IPosition¹M, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 1D space
        Vector1M        position() const override { return m_position; }

        Meter           position(x_k) const { return m_position.x; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector1M&) override;
        void            position(set_k, x_k, Meter) override;
        
        //!  Move the position (ie set to position + delta)
        void            position(add_k, const Vector1M&) override;
        void            position(add_k, x_k, Meter) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector1D&) override;
        void            position(multiply_k, x_k, double) override;
        
        bool            position(disabled_k) const { return false; }
        bool            position(settable_k) const { return true; }
        bool            position(addable_k) const { return true; }
        bool            position(multipliable_k) const { return true; }

        const Vector1M& position(ref_k) const { return m_position; }

    protected:
        
        Vector1M    m_position = ZERO;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition¹M();
        virtual ~APosition¹M();

        void            position(emit_k);
        
    private:
        void        on_set_position1(const SetPosition¹MCommand&);
        void        on_set_positionX(const SetPositionˣMCommand&);

        void        on_add_position1(const AddPosition¹MCommand&);
        void        on_add_positionX(const AddPositionˣMCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position1(const MultiplyPosition¹DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);

    };

}
