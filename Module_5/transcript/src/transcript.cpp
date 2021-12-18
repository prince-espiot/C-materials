#include "transcript.hpp"
#include <iostream>
#include <algorithm>

void TranscriptRegistry::Add(const Transcript &transcript)
{
    transcripts_.push_back(transcript);
}

const std::list<Transcript> TranscriptRegistry::GetTranscripts() const
{
    return transcripts_;
}

void TranscriptRegistry::RemoveById(const std::string &id)
{
  for (std::list<Transcript>::iterator transcript = transcripts_.begin(); transcript != transcripts_.end();)
        if (transcript->student_id == id)
            transcript = transcripts_.erase(transcript);
        else
            ++transcript;
}

std::list<Transcript>::const_iterator TranscriptRegistry::FindTranscript(const std::string &id) const
{
    return find_if(transcripts_.begin(), transcripts_.end(),
                   [=](Transcript t)
                   {
                       return id <= t.student_id;
                   });
    ;
}

std::list<std::pair<std::string, size_t> > TranscriptRegistry::FindCourseResults(std::string course) const
{
    std::list<std::pair<std::string, size_t>> tran;
    for_each(transcripts_.begin(),transcripts_.end(), [&](Transcript const & transcript)
        {
            for (auto &gr : transcript.grades)
            {
                if (gr.first == course) {
                    std::pair<std::string, size_t> par;
                    par.first = transcript.student_id;
                    par.second = gr.second;
                    tran.push_back(par);
                }
                    
            }
            
        });
    return tran;
}