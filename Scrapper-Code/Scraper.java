import com.opencsv.CSVWriter;
import io.github.bonigarcia.wdm.WebDriverManager;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.openqa.selenium.*;
import org.openqa.selenium.edge.EdgeDriver;

import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.util.ArrayList;
import java.util.List;

/**
 * The Scraper class is responsible for scraping LeetCode problem data from the website.
 */
public class Scraper {

    private static final String USERNAME = ""; // Provide your LeetCode username
    private static final String PASSWORD = ""; // Provide your LeetCode password
    public static final int QUESTIONS_PAGE_WAIT_MILLIS = 25000;
    public static final int LOGIN_PAGE_WAIT_MILLIS = 2000;
    WebDriver driver;
    List<String> companyURLs = new ArrayList<>();

    /**
     * Sets up the WebDriver and logs in to the LeetCode account.
     *
     * @throws InterruptedException Thrown when a thread is waiting, sleeping, or otherwise occupied
     * @throws IOException          Signals that an I/O exception has occurred
     */
    public void setup() throws InterruptedException, IOException {
        WebDriverManager.edgedriver().setup();
        driver = new EdgeDriver();

        driver.get("https://leetcode.com/accounts/login/");
        driver.manage().timeouts().implicitlyWait(Duration.ofSeconds(1));
        if (USERNAME.isEmpty() || PASSWORD.isEmpty()) {
            throw new IllegalArgumentException("Username or password can't be empty");
        }
        driver.findElement(By.xpath("// *[ @ id = 'id_login']")).sendKeys(USERNAME);
        driver.findElement(By.xpath("// *[ @ id = 'id_password']")).sendKeys(PASSWORD);
        driver.findElement(By.xpath("// *[ @ id = 'id_password']")).sendKeys(Keys.ENTER);
        Thread.sleep(LOGIN_PAGE_WAIT_MILLIS);
        driver.get("https://leetcode.com/problemset/all/");
        List<WebElement> companies = driver.findElements(By.cssSelector(".mb-4.mr-3"));
        for (WebElement company : companies) {
            String link = company.getAttribute("href");
            System.out.println(link);
            companyURLs.add(link);
        }
        for (String companyURL : companyURLs) {
            visitCompanies(companyURL);
        }
    }

    /**
     * Visits a specific company's LeetCode page and extracts problem data.
     *
     * @param companyURL The URL of the company's LeetCode page
     * @throws InterruptedException Thrown when a thread is waiting, sleeping, or otherwise occupied
     * @throws IOException          Signals that an I/O exception has occurred
     */
    private void visitCompanies(String companyURL) throws InterruptedException, IOException {
        String companyName = companyURL.substring(companyURL.lastIndexOf("/") + 1);
        System.out.println("Visiting " + companyURL);
        driver.get(companyURL);
        Thread.sleep(QUESTIONS_PAGE_WAIT_MILLIS);
        String table = "";
        try {
            table = "<table>" + driver.findElement(By.className("table")).getAttribute("innerHTML") + "</table>";
        } catch (NoSuchElementException ex) {
            Thread.sleep(30000);
            driver.get(companyURL);
            Thread.sleep(30000);
            table = "<table>" + driver.findElement(By.className("table")).getAttribute("innerHTML") + "</table>";
        }
        Document doc = Jsoup.parse(table);
        List<String[]> result = new ArrayList<>();
        String[] header = new String[]{"ID", "Title", "URL", "Is Premium", "Acceptance %", "Difficulty", "Frequency %"};
        result.add(header);
        for (Element row : doc.getElementsByTag("tr")) {
            Elements cols = row.getElementsByTag("td");
            int size = cols.size();
            if (size != 0) {
                String id = cols.get(1).text();
                String title = cols.get(2).text();
                Elements href = cols.get(2).getElementsByAttribute("href");
                boolean isPremium = !cols.get(2).getElementsByTag("i").isEmpty();
                String problemUrl = href.get(0).attr("href");
                String acceptance = cols.get(3).text();
                String difficulty = cols.get(4).getElementsByTag("span").text();
                String frequency = cols.get(5).getElementsByClass("progress-bar").attr("style");
                frequency = frequency.substring(frequency.indexOf(" ") + 1);
                String[] res = new String[]{id, title, problemUrl, isPremium ? "Y" : "N", acceptance, difficulty, frequency};
                result.add(res);
            }
        }
        try (CSVWriter csvWriter = new CSVWriter(new FileWriter(companyName + ".csv"))) {
            csvWriter.writeAll(result);
        }
    }
}
