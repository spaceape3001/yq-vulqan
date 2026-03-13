////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ICount4U.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddCount⁴UCommand;
    class AddCountʷUCommand;
    class AddCountˣUCommand;
    class AddCountʸUCommand;
    class AddCountᶻUCommand;
    class MultiplyCountUCommand;   // here due to copy & paste, however
    class MultiplyCount⁴UCommand;  // might go for it (later)
    class MultiplyCountʷUCommand;
    class MultiplyCountˣUCommand;
    class MultiplyCountʸUCommand;
    class MultiplyCountᶻUCommand;
    class SetCount⁴UCommand;
    class SetCountʷUCommand;
    class SetCountˣUCommand;
    class SetCountʸUCommand;
    class SetCountᶻUCommand;

    class ACount⁴U : public ICount⁴U, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector4U    count   = ONE;
        };
    
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
        
        Vector4U    m_count;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ACount⁴U(const Param&);
        ACount⁴U(const Vector4U& cnt=ONE);
        virtual ~ACount⁴U();
        
        void        count(emit_k);

    private:
        void        on_set_count4(const SetCount⁴UCommand&);
        void        on_set_countW(const SetCountʷUCommand&);
        void        on_set_countX(const SetCountˣUCommand&);
        void        on_set_countY(const SetCountʸUCommand&);
        void        on_set_countZ(const SetCountᶻUCommand&);

        void        on_add_count4(const AddCount⁴UCommand&);
        void        on_add_countW(const AddCountʷUCommand&);
        void        on_add_countX(const AddCountˣUCommand&);
        void        on_add_countY(const AddCountʸUCommand&);
        void        on_add_countZ(const AddCountᶻUCommand&);
        
        void        on_multiply_count(const MultiplyCountUCommand&);
        void        on_multiply_count4(const MultiplyCount⁴UCommand&);
        void        on_multiply_countW(const MultiplyCountʷUCommand&);
        void        on_multiply_countX(const MultiplyCountˣUCommand&);
        void        on_multiply_countY(const MultiplyCountʸUCommand&);
        void        on_multiply_countZ(const MultiplyCountᶻUCommand&);
    };
}
