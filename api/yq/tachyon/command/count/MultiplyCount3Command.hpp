////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyCount³Command : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount³Command, CountCommand)
    public:
        MultiplyCount³Command(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        unsigned  δy() const { return m_δ.y; }
        unsigned  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCount³Command(const MultiplyCount³Command&, const Header&);
        MultiplyCount³Command(const Header&);
        ~MultiplyCount³Command();

    private:
        Vector3D  m_δ;
        
        MultiplyCount³Command(const MultiplyCount³Command&) = delete;
        MultiplyCount³Command(MultiplyCount³Command&&) = delete;
        MultiplyCount³Command& operator=(const MultiplyCount³Command&) = delete;
        MultiplyCount³Command& operator=(MultiplyCount³Command&&) = delete;
    };
}
