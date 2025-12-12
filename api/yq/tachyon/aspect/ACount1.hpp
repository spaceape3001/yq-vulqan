////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/ICount1.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddCount¹Command;
    class AddCountˣCommand;
    class MultiplyCountCommand;
    class MultiplyCount¹Command;
    class MultiplyCountˣCommand;
    class SetCount¹Command;
    class SetCountˣCommand;

    class ACount¹ : public ICount¹, public virtual Tachyon::Helper {
    public:
    
        //!  Basic count in the 1D space
        Vector1U        count() const override { return m_count; }

        unsigned          count(x_k) const { return m_count.x; }
        
        //!  Set count the count (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    count(set_k, const Vector1U&) override;
        void            count(set_k, x_k, unsigned) override;
        
        //!  Move the count (ie set to count + delta)
        void            count(add_k, const Vector1U&) override;
        void            count(add_k, x_k, unsigned) override;

        void            count(multiply_k, unsigned) override;
        void            count(multiply_k, const Vector1U&) override;
        void            count(multiply_k, x_k, unsigned) override;
        
        bool            count(disabled_k) const { return false; }
        bool            count(settable_k) const { return true; }
        bool            count(addable_k) const { return true; }
        bool            count(multipliable_k) const { return true; }

        const Vector1U& count(ref_k) const { return m_count; }

    protected:
        
        Vector1U    m_count = ONE;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ACount¹(const Vector1U& cnt=ONE);
        virtual ~ACount¹();

        void            count(emit_k);
        
    private:
        void        on_set_count1(const SetCount¹Command&);
        void        on_set_countX(const SetCountˣCommand&);

        void        on_add_count1(const AddCount¹Command&);
        void        on_add_countX(const AddCountˣCommand&);
        
        void        on_multiply_count(const MultiplyCountCommand&);
        void        on_multiply_count1(const MultiplyCount¹Command&);
        void        on_multiply_countX(const MultiplyCountˣCommand&);

    };

}
