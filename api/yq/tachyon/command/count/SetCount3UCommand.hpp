////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCount³Command : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount³Command, CountCommand)
    public:
        SetCount³Command(const Header&, const Vector3U&);
    
        const Vector3U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        unsigned  y() const { return m_count.y; }
        unsigned  z() const { return m_count.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount³Command(const Header&);
        SetCount³Command(const SetCount³Command&, const Header&);
        ~SetCount³Command();

    private:
        Vector3U   m_count = ZERO;
        
        SetCount³Command(const SetCount³Command&) = delete;
        SetCount³Command(SetCount³Command&&) = delete;
        SetCount³Command& operator=(const SetCount³Command&) = delete;
        SetCount³Command& operator=(SetCount³Command&&) = delete;
    };
}
