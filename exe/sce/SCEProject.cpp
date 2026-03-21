////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SCEProject.hpp"
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(SCEProject)

SCEProject::SCEProject() /* : SCEProject( */
{

}

SCEProject::SCEProject(const std::filesystem::path& fp)
{
}

SCEProject::~SCEProject()
{
}

void        SCEProject::snap(SCEProjectSnap&sn) const
{
    Tachyon::snap(sn);
}

void SCEProject::init_meta()
{
    auto w = writer<SCEProject>();
    w.description("Scene Editor Project");
}



#include "moc_SCEProject.cpp"

