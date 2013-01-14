#include "../include/FileProcessor.h"

FileProcessor::FileProcessor(wxString filename, wxString delim,wxString tblname)
{
    setFileName(filename);
    setDelim(delim);
    setFileMode(true);
    setTableName(tblname);
    inFile = new wxTextFile();
    outFile = new wxTextFile();

    inFile->Open(filename);
    outFile->Create(wxT("dbout.tmp"));
}

FileProcessor::~FileProcessor()
{
    //dtor
}

void FileProcessor::clearMysqlCols()
{
    mysqlCols.clear();
}

int FileProcessor::checkError()
{
    // Check if all parameters are set
    if(delimiter.IsNull() || delimiter.IsEmpty())
        return 1;
    if(fileName.IsNull() || fileName.IsEmpty())
        return 2;
    if(mysqlCols.empty())
        return 3;
    if(tableName.IsEmpty() || tableName.IsNull())
        return 4;

    return 0;
}

// Setters
void FileProcessor::setDelim(wxString delim)
{
    delimiter = delim;
}

void FileProcessor::setFileName(wxString name)
{
    fileName = name;
}

void FileProcessor::addMysqlCols(wxString column)
{
    mysqlCols.push_back(column);
}

void FileProcessor::setFileMode(bool on)
{
    continuousFileOutput = on; // If true, outputs a file as it iterates.
                               // If false, saves to a vector and outputs file when done.
}

void FileProcessor::setTableName(wxString name)
{
    tableName = name;
}

// Getters
wxString FileProcessor::getFileName()
{
    return fileName;
}

wxString FileProcessor::getDelim()
{
    return delimiter;
}



wxString FileProcessor::getTableName()
{
    return tableName;
}

void FileProcessor::write(columns buff)
{
    if(continuousFileOutput)
    {
        int itr = 0;
        wxString tmp = wxT("(");

        while(!buff.empty() && itr<nCols)
        {
            if(itr>0)
                tmp += wxT(",");
            tmp += wxT('"');
            tmp += buff.front();
            tmp += wxT('"');
            buff.pop_front();
            itr++;
        }
        tmp += wxT("),");
        outFile->AddLine(tmp);
    }
    else
    {
        rows.push_back(buff);
    }
}

void FileProcessor::read()
{
    if(!inFile->IsOpened())
        inFile->Open(fileName);


    wxString str;
    for(str = inFile->GetFirstLine(); !inFile->Eof(); str = inFile->GetNextLine())
    {
        columns rowSplit;
        wxStringTokenizer tkz(str,delimiter);
        while(tkz.HasMoreTokens())
        {
            wxString token = tkz.GetNextToken();
            rowSplit.push_back(token);
        }
        write(rowSplit);
    }
}

void FileProcessor::prepare()
{
    wxString intro = wxT("INSERT INTO ");
    intro += tableName;
    intro += wxT("(");

    int itr=0;
    for(columns_itr it = mysqlCols.begin(); it != mysqlCols.end(); it++)
    {
        if(itr>0)
            intro += wxT(",");
        intro += *it;
        itr++;
    }
    nCols = itr;

    intro += wxT(") VALUES ");
    fileIntro = intro;

}

void FileProcessor::dumpTmpFile()
{
    continuousFileOutput = !continuousFileOutput;

    for(row_itr it = rows.begin(); it != rows.end(); it++)
    {
        write(*it);
    }
}

int FileProcessor::run()
{
    int e = checkError();
    if(e>0)
        return e;
    prepare();
    read();
    return 0;
}
