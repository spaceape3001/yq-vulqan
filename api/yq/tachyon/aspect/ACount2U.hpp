////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ICount2U.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddCount²UCommand;
    class AddCountˣUCommand;
    class AddCountʸUCommand;
    class MultiplyCountUCommand;
    class MultiplyCount²UCommand;
    class MultiplyCountˣUCommand;
    class MultiplyCountʸUCommand;
    class SetCount²UCommand;
    class SetCountˣUCommand;
    class SetCountʸUCommand;

    class ACount²U : public ICount²U, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector2U    count   = ONE;
        };
        
        //!  Basic count in the 2D space
        Vector2U        count() const override { return m_count; }
        
        unsigned          count(x_k) const { return m_count.x; }
        unsigned          count(y_k) const { return m_count.y; }

        //!  Set count the count (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    count(set_k, const Vector2U&) override;
        void            count(set_k, x_k, unsigned) override;
        void            count(set_k, y_k, unsigned) override;
        
        //!  Move the count (ie set to count + delta)
        void            count(add_k, const Vector2U&) override;
        void            count(add_k, x_k, unsigned) override;
        void            count(add_k, y_k, unsigned) override;

        void            count(multiply_k, unsigned) override;
        void            count(multiply_k, const Vector2U&) override;
        void            count(multiply_k, x_k, unsigned) override;
        void            count(multiply_k, y_k, unsigned) override;
        
        bool            count(disabled_k) const { return false; }
        bool            count(settable_k) const { return true; }
        bool            count(addable_k) const { return true; }
        bool            count(multipliable_k) const { return true; }

        const Vector2U& count(ref_k) const { return m_count; }

    protected:

        Vector2U        m_count;
    
        void            count(emit_k);
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ACount²U(const Param&);
        ACount²U(const Vector2U& cnt = ONE);
        virtual ~ACount²U();
        
    private:
        void        on_set_count2(const SetCount²UCommand&);
        void        on_set_countX(const SetCountˣUCommand&);
        void        on_set_countY(const SetCountʸUCommand&);

        void        on_add_count2(const AddCount²UCommand&);
        void        on_add_countX(const AddCountˣUCommand&);
        void        on_add_countY(const AddCountʸUCommand&);
        
        void        on_multiply_count(const MultiplyCountUCommand&);
        void        on_multiply_count2(const MultiplyCount²UCommand&);
        void        on_multiply_countX(const MultiplyCountˣUCommand&);
        void        on_multiply_countY(const MultiplyCountʸUCommand&);
    };
}
