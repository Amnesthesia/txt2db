#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <list>
#include <wx/textfile.h>
#include <wx/tokenzr.h>

typedef std::list<wxString> columns;
typedef columns::iterator columns_itr;
typedef std::list<columns> rowContainer;
typedef rowContainer::iterator row_itr;

class FileProcessor
{
    public:
        FileProcessor(wxString filename,wxString delimiter,wxString tblname);
        virtual ~FileProcessor();

        void clearMysqlCols();
        int checkError();
        int run();
        void dumpTmpFile();

        // Setters
        void setDelim(wxString delim);
        void setFileName(wxString name);
        void addMysqlCols(wxString column);
        void setFileMode(bool on);
        void setTableName(wxString name);

        // Getters
        wxString getFileName();
        wxString getDelim();
        wxString getTableName();
    protected:
    private:
        int nCols;
        wxString fileIntro;
        wxString delimiter;
        wxString fileName;
        wxString tableName;
        columns mysqlCols;
        rowContainer rows;
        bool continuousFileOutput;
        wxTextFile* inFile;
        wxTextFile* outFile;
        void write(columns buff);
        void read();
        void prepare();
};

#endif // FILEPROCESSOR_H
