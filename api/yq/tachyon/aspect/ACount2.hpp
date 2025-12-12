////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ICount2.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddCount²Command;
    class AddCountˣCommand;
    class AddCountʸCommand;
    class MultiplyCountCommand;
    class MultiplyCount²Command;
    class MultiplyCountˣCommand;
    class MultiplyCountʸCommand;
    class SetCount²Command;
    class SetCountˣCommand;
    class SetCountʸCommand;

    class ACount² : public ICount², public virtual Tachyon::Helper {
    public:
    
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

        Vector2U        m_count = ONE;
    
        void            count(emit_k);
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ACount²(const Vector2U& cnt = ONE);
        virtual ~ACount²();
        
    private:
        void        on_set_count2(const SetCount²Command&);
        void        on_set_countX(const SetCountˣCommand&);
        void        on_set_countY(const SetCountʸCommand&);

        void        on_add_count2(const AddCount²Command&);
        void        on_add_countX(const AddCountˣCommand&);
        void        on_add_countY(const AddCountʸCommand&);
        
        void        on_multiply_count(const MultiplyCountCommand&);
        void        on_multiply_count2(const MultiplyCount²Command&);
        void        on_multiply_countX(const MultiplyCountˣCommand&);
        void        on_multiply_countY(const MultiplyCountʸCommand&);
    };
}
