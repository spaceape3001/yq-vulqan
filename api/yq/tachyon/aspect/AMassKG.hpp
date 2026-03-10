////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IMassKG.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetMassKGCommand;
    class AddMassKGCommand;
    class MultiplyMassCommand;

    class AMassKG : public IMassKG, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Kilogram  mass = 1._kg;
        };
        
        virtual Kilogram  mass() const override { return m_mass; }
        
        virtual void    mass(add_k, Kilogram) override;
        virtual void    mass(multiply_k, double) override;
        virtual void    mass(set_k, Kilogram) override;
        
    
        virtual bool    mass(disabled_k) const override { return false; }
        virtual bool    mass(settable_k) const override { return true; }
        virtual bool    mass(addable_k) const override { return true; }
        virtual bool    mass(multipliable_k) const override { return true; }

    protected:
        Kilogram  m_mass;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AMassKG(const Param&);
        AMassKG(Kilogram kg=1._kg);
        virtual ~AMassKG();

        void            mass(emit_k);
        
    private:
        void on_set_mass_command(const SetMassKGCommand&);
        void on_add_mass_command(const AddMassKGCommand&);
        void on_multiply_mass_command(const MultiplyMassCommand&);
    };
}

