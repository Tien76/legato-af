//--------------------------------------------------------------------------------------------------
/**
 * @file defFile.h
 */
//--------------------------------------------------------------------------------------------------

#ifndef LEGATO_MKTOOLS_PARSE_TREE_DEF_FILE_H_INCLUDE_GUARD
#define LEGATO_MKTOOLS_PARSE_TREE_DEF_FILE_H_INCLUDE_GUARD


//--------------------------------------------------------------------------------------------------
/**
 * Represents a parsed .Xdef file.
 */
//--------------------------------------------------------------------------------------------------
struct DefFile_t
{
    enum Type_t
    {
        CDEF,
        ADEF,
        SDEF
    };

    Type_t type;        ///< The type of file.

    std::string path;   ///< The file system path to the file.

    size_t version;     ///< File format version number (0 = unknown, 1 = first version).

    Token_t* firstTokenPtr; ///< Ptr to the first token in the file.
    Token_t* lastTokenPtr;  ///< Ptr to the last token in the file.

    std::list<CompoundItem_t*> sections; ///< List of top-level sections in the file.

protected:

    /// Constructor
    DefFile_t(Type_t type, const std::string& filePath);
};


//--------------------------------------------------------------------------------------------------
/**
 * Represents a parsed .cdef file.
 */
//--------------------------------------------------------------------------------------------------
struct CdefFile_t : public DefFile_t
{
    CdefFile_t(const std::string& filePath): DefFile_t(CDEF, filePath) {}
};


//--------------------------------------------------------------------------------------------------
/**
 * Represents a parsed .adef file.
 */
//--------------------------------------------------------------------------------------------------
struct AdefFile_t : public DefFile_t
{
    AdefFile_t(const std::string& filePath): DefFile_t(ADEF, filePath) {}
};


//--------------------------------------------------------------------------------------------------
/**
 * Represents a parsed .sdef file.
 */
//--------------------------------------------------------------------------------------------------
struct SdefFile_t : public DefFile_t
{
    SdefFile_t(const std::string& filePath): DefFile_t(SDEF, filePath) {}
};



#endif // LEGATO_MKTOOLS_PARSE_TREE_DEF_FILE_H_INCLUDE_GUARD
