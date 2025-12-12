////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ICount4.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddCount⁴Command;
    class AddCountʷCommand;
    class AddCountˣCommand;
    class AddCountʸCommand;
    class AddCountᶻCommand;
    class MultiplyCountCommand;   // here due to copy & paste, however
    class MultiplyCount⁴Command;  // might go for it (later)
    class MultiplyCountʷCommand;
    class MultiplyCountˣCommand;
    class MultiplyCountʸCommand;
    class MultiplyCountᶻCommand;
    class SetCount⁴Command;
    class SetCountʷCommand;
    class SetCountˣCommand;
    class SetCountʸCommand;
    class SetCountᶻCommand;

    class ACount⁴ : public ICount⁴, public virtual Tachyon::Helper {
    public:
    
        //!  Basic count in the 4D space
        Vector4U        count() const override { return m_count; }

        unsigned          count(x_k) const { return m_count.x; }
        unsigned          count(y_k) const { return m_count.y; }
        unsigned          count(z_k) const { return m_count.z; }
        unsigned          count(w_k) const { return m_count.w; }
        
        //!  Set count the count (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    count(set_k, const Vector4U&) override;
        void            count(set_k, x_k, unsigned) override;
        void            count(set_k, y_k, unsigned) override;
        void            count(set_k, z_k, unsigned) override;
        void            count(set_k, w_k, unsigned) override;
        
        //!  Add the count (ie set to count + delta)
        void            count(add_k, const Vector4U&) override;
        void            count(add_k, x_k, unsigned) override;
        void            count(add_k, y_k, unsigned) override;
        void            count(add_k, z_k, unsigned) override;
        void            count(add_k, w_k, unsigned) override;

        void            count(multiply_k, unsigned) override;
        void            count(multiply_k, const Vector4U&) override;
        void            count(multiply_k, x_k, unsigned) override;
        void            count(multiply_k, y_k, unsigned) override;
        void            count(multiply_k, z_k, unsigned) override;
        void            count(multiply_k, w_k, unsigned) override;
        
        virtual bool    count(disabled_k) const override { return false; }
        virtual bool    count(settable_k) const override { return true; }
        virtual bool    count(addable_k) const override { return true; }
        virtual bool    count(multipliable_k) const override { return true; }

        const Vector4U& count(ref_k) const { return m_count; }

    protected:
        
        Vector4U    m_count = ONE;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ACount⁴(const Vector4U& cnt=ONE);
        virtual ~ACount⁴();
        
        void        count(emit_k);

    private:
        void        on_set_count4(const SetCount⁴Command&);
        void        on_set_countW(const SetCountʷCommand&);
        void        on_set_countX(const SetCountˣCommand&);
        void        on_set_countY(const SetCountʸCommand&);
        void        on_set_countZ(const SetCountᶻCommand&);

        void        on_add_count4(const AddCount⁴Command&);
        void        on_add_countW(const AddCountʷCommand&);
        void        on_add_countX(const AddCountˣCommand&);
        void        on_add_countY(const AddCountʸCommand&);
        void        on_add_countZ(const AddCountᶻCommand&);
        
        void        on_multiply_count(const MultiplyCountCommand&);
        void        on_multiply_count4(const MultiplyCount⁴Command&);
        void        on_multiply_countW(const MultiplyCountʷCommand&);
        void        on_multiply_countX(const MultiplyCountˣCommand&);
        void        on_multiply_countY(const MultiplyCountʸCommand&);
        void        on_multiply_countZ(const MultiplyCountᶻCommand&);
    };
}
