import java.util.Calendar;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {

        Map<Integer, String> dow = new HashMap<>();
        dow.put(1, "Sunday");
        dow.put(2, "Monday");
        dow.put(3, "Tuesday");
        dow.put(4, "Wednesday");
        dow.put(5, "Thursday");
        dow.put(6, "Friday");
        dow.put(7, "Saturday");

        Calendar cal = Calendar.getInstance();
        cal.set(2013, Calendar.MAY, 29);
        int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK);

        System.out.println("May 29, 2013 " + dow.get(dayOfWeek));
    }
}
