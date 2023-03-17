package Week1;

import java.util.*;

class Student {
	private Vector<Transcript> transcripts;
	private String name;

	public Student(String name) {
		this.name = name;
		transcripts = new Vector<Transcript>();
	}

	public void addTranscript(Transcript transcript) {
		transcripts.add(transcript);
	}
	public String getName() {
		return name;
	}
	public Vector<Course> getCourses(){
		Vector<Course> courses = new Vector<Course>();
		Iterator<Transcript> itor = transcripts.iterator();
		
		while (itor.hasNext()) {
			Transcript tr = itor.next();
			courses.add(tr.getCourse());
		}
		return courses;
	}
}

